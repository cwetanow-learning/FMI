using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DiagramStuff.Models;
using NUnit.Framework.Internal;
using NUnit.Framework;

namespace Tests
{
    [TestFixture]
    class InvoiceTests
    {
        [TestCase("Nice part", "12345", 5, 4.0)]
        [TestCase("Nice part 2", "65775", 15, 44.5)]
        public void TestConstructor_ShouldInitialiseCorrectly(
            string description,
            string number,
            int quantity,
            decimal price)
        {
            var invoice = new Invoice(description, number, quantity, price);

            Assert.IsNotNull(invoice);
            Assert.AreEqual(description, invoice.PartDescription);
            Assert.AreEqual(number, invoice.PartNumber);
            Assert.AreEqual(quantity, invoice.Quantity);
            Assert.AreEqual(price, invoice.Price);
        }

        [TestCase(5, 22.0)]
        [TestCase(12, 55.5)]
        public void TestGetInvoiceAmount_ShouldReturnCorrectAmount(int quantity, decimal price)
        {
            var invoice = new Invoice(null, null, quantity, price);

            var expected = quantity * price;
            var actual = invoice.GetInvoiceAmount();

            Assert.AreEqual(expected, actual);
        }
    }
}
