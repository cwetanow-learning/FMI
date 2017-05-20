using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Moq;
using NUnit.Framework;
using Project1.Contracts;

namespace Tests
{
    [TestFixture]
    class GradeBookTests
    {
        [TestCase("CS101 Introduction to C# Programming", "Pesho")]
        [TestCase("CS102 Data Structures in C#", "Stamat")]
        public void TestConstructor_ShouldInitialiseCorrectly(string courseName, string instructorName)
        {
            var gradeBook = new GradeBook(null, courseName, instructorName);

            Assert.IsNotNull(gradeBook);
            Assert.AreEqual(courseName, gradeBook.CourseName);
            Assert.AreEqual(instructorName, gradeBook.InstructorName);
        }

        [TestCase("CS101 Introduction to C# Programming", "Pesho")]
        [TestCase("CS102 Data Structures in C#", "Stamat")]
        public void TestDisplayMessage_ShouldReturnCorrectMessage(string courseName, string instructorName)
        {
            var mockedWriter = new Mock<IWriter>();

            var gradeBook = new GradeBook(mockedWriter.Object, courseName, instructorName);

            gradeBook.DisplayMessage();

            var expectedMessage =
                $"Welcome to the grade book for\n{courseName}! This course is presented by: {instructorName}";

            mockedWriter.Verify(x => x.WriteLine(expectedMessage), Times.Once);
        }
    }
}
