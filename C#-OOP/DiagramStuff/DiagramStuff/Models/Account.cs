using System;
using DiagramStuff.Utils;

namespace DiagramStuff.Models
{
    public class Account
    {
        private decimal balance;
        private double anualInterestRate;
        private DateTime dateCreated;
        private int id;

        public Account()
        {
            this.Id = DataGenerator.GenerateId();
        }

        public Account(decimal balance, double anualRate, DateTime dateCreated)
        {
            this.Id = DataGenerator.GenerateId();
            this.Balance = balance;
            this.AnualInterestRate = anualRate;
            this.DateCreated = dateCreated;
        }

        public decimal Balance
        {
            get
            {
                return this.balance;
            }
            set
            {
                if (value < 0)
                {
                    throw new ArgumentException("Balance cannot be negative");
                }

                this.balance = value;
            }
        }

        public double AnualInterestRate
        {
            get
            {
                return this.anualInterestRate;
            }
            set
            {
                this.anualInterestRate = value;
            }
        }

        public DateTime DateCreated
        {
            get
            {
                return this.dateCreated;
            }
            set
            {
                this.dateCreated = value;
            }
        }

        public int Id
        {
            get
            {
                return this.id;
            }
            set
            {
                this.id = value;
            }
        }

        public void Deposit(decimal amount)
        {
            if (amount <= 0)
            {
                throw new ArgumentOutOfRangeException("Amount to deposit cannot be negative");
            }

            this.balance += amount;
        }

        public decimal Withdraw(decimal amount)
        {
            if (amount <= 0)
            {
                throw new ArgumentOutOfRangeException("Amount to deposit cannot be negative");
            }

            this.balance -= amount;

            return amount;
        }
    }
}
