using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;
using Microsoft.Win32;
using Sudoku.Models;
using Sudoku.Models.Enums;

namespace Sudoku.WPFClient
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private readonly IEnumerable<Grid> children;

        private SudokuGame game;
        private GameGenerator generator;

        private DispatcherTimer dispatcher;
        private Stopwatch timer;

        public MainWindow()
        {
            this.SetupTimers();

            InitializeComponent();

            this.children = GetChildren();
        }

        private IEnumerable<Grid> GetChildren()
        {
            var kids = ((Panel)this.Content)?.Children
                .OfType<SudokuControl>()
                .FirstOrDefault()?
                .Grid
                .Children
                .Cast<Border>()
                .Select(b => b.Child)
                .Cast<Grid>();

            return kids;
        }

        private void SetupTimers()
        {
            this.dispatcher = new DispatcherTimer();
            this.timer = new Stopwatch();

            this.dispatcher.Tick += Dispatcher_Tick;
            this.dispatcher.Interval = new TimeSpan(0, 0, 1);
        }

        private void Dispatcher_Tick(object sender, EventArgs e)
        {
            if (this.timer.IsRunning)
            {
                var elapsed = this.timer.Elapsed.Add(this.game.Elapsed);
                var currentTime = $"{elapsed.Hours:00}:{elapsed.Minutes:00}:{elapsed.Seconds:00}";

                this.TxtBoxElapsed.Text = currentTime;
            }
        }

        private void BtnSave_OnClick(object sender, RoutedEventArgs e)
        {
            if (this.game == null)
            {
                MessageBox.Show(this, "There is no game on board");
                return;
            }

            var saveFileDialog = new SaveFileDialog();

            var result = saveFileDialog.ShowDialog();
            if (result != null && result.Value)
            {
                using (var stream = File.Open(saveFileDialog.FileName, FileMode.Create))
                {
                    this.game.Elapsed = this.timer.Elapsed;

                    var serializer = new BinaryFormatter();
                    serializer.Serialize(stream, this.game);
                }
            }
        }

        private void BtnLoad_OnClick(object sender, RoutedEventArgs e)
        {
            var fileDialog = new OpenFileDialog();
            var result = fileDialog.ShowDialog();

            if (result != null && result.Value)
            {
                using (var stream = File.Open(fileDialog.FileName, FileMode.Open))
                {
                    var binaryFormatter = new BinaryFormatter();
                    var savedGame = (SudokuGame)binaryFormatter.Deserialize(stream);
                    this.game = savedGame;

                    this.FillBoard();

                    this.timer.Restart();
                    this.dispatcher.Start();
                }
            }
        }

        private void DifficultyBox_OnLoaded(object sender, RoutedEventArgs e)
        {
            this.DifficultyBox.ItemsSource = Enum.GetValues(typeof(Difficulty));
            this.DifficultyBox.SelectedIndex = 0;
        }

        private void BtnNewGame_OnClick(object sender, RoutedEventArgs e)
        {
            this.generator = new GameGenerator();

            var board = this.generator.GetGame((Difficulty)this.DifficultyBox.SelectionBoxItem);

            this.game = new SudokuGame(board);

            this.FillBoard();

            if (this.timer.IsRunning)
            {
                this.timer.Restart();
            }
            else
            {
                this.timer.Start();
            }

            this.dispatcher.Start();
        }

        private void FillBoard()
        {
            foreach (var child in this.children)
            {
                var kids = child
                    .Children;

                foreach (var kid in kids)
                {
                    var box = (TextBox)kid;
                    box.Text = "";

                    var indexes = (box)?.Name.Split('_')[1];
                    var x = indexes[0] - '0';
                    var y = indexes[1] - '0';

                    var number = this.game.Board[x, y];

                    if (number != 0)
                    {
                        box.Text = number.ToString();
                        box.IsReadOnly = true;
                    }
                }
            }

        }

        private void FillTable()
        {
            foreach (var child in this.children)
            {
                var kids = child.Children;

                foreach (var kid in kids)
                {
                    var box = (TextBox)kid;

                    var indexes = (box)?.Name.Split('_')[1];
                    var x = indexes[0] - '0';
                    var y = indexes[1] - '0';

                    if (this.game.Board[x, y] == 0)
                    {
                        this.game.Board[x, y] = int.Parse(box.Text);
                    }
                }
            }
        }

        private bool IsFull()
        {
            foreach (var child in this.children)
            {
                var kids = child.Children;

                foreach (var kid in kids)
                {
                    var box = (TextBox)kid;

                    if (box.Text.Length == 0)
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        private void BtnCheck_OnClick(object sender, RoutedEventArgs e)
        {
            if (this.game == null)
            {
                MessageBox.Show(this, "There is no game");
                return;
            }

            if (!this.IsFull())
            {
                MessageBox.Show(this, "Board is not full");
                return;
            }

            this.timer.Stop();
            this.dispatcher.Stop();

            this.FillTable();

            var checker = GameChecker.Instance;
            var isSolved = checker.Validate(this.game.Board);

            if (isSolved)
            {
                MessageBox.Show(this, "Congratulations");
            }
            else
            {
                this.timer.Start();
                this.dispatcher.Start();
            }
        }

        private void BtnClear_OnClick(object sender, RoutedEventArgs e)
        {
            foreach (var child in this.children)
            {
                var kids = child.Children;

                foreach (var kid in kids)
                {
                    var box = (TextBox)kid;

                    if (!box.IsReadOnly)
                    {
                        box.Text = string.Empty;
                    }
                }
            }
        }

        private void ButtonBase_OnClick(object sender, RoutedEventArgs e)
        {
            Environment.Exit(0);
        }
    }
}
