using System;
using System.Collections.Generic;
using System.Linq;

namespace Linq.Tasks
{
    public class Startup
    {
        public static void Main(string[] args)
        {
            var invoices = new List<Invoice>
            {
                new Invoice(83, "Electric sander", 7 ,57.98m),
                 new Invoice(24," Power saw", 18 ,99.99m),
                new Invoice(83, "Electric sander", 7 ,57.98m),
                 new Invoice(24," Power saw", 18 ,99.99m),
                new Invoice(83, "Electric sander", 7 ,57.98m),
                 new Invoice(24," Power saw", 18 ,99.99m),
                new Invoice(83, "Electric sander", 7 ,57.98m),
                 new Invoice(224," Power saw", 18 ,299.99m),
            };

            Print(SortByPartDescription(invoices));
            Console.WriteLine();
            Print(SortByPrice(invoices));
            Console.WriteLine();
            Print(GetInvoicesBetween200And500(invoices));

            var groupedIntoTwo = invoices
                .OrderBy(x => x.Price)
                .GroupBy(x => x.Price < 12);

            var groupedIntoThree = invoices
                .GroupBy(x =>
                x.Price < 12 ? 0 :
                    x.Price > 20 ? 1 : 2);

            Console.WriteLine();
            foreach (var inv in SelectDescriptionValue(invoices))
            {
                Console.WriteLine(inv);
            }

        }

        private static void Print(IEnumerable<Invoice> invoices)
        {
            foreach (var invoice in invoices)
            {
                Console.WriteLine($"{invoice.Price} {invoice.PartDescription} {invoice.Quantity} {invoice.PartNumber}");
            }
        }

        private static IEnumerable<Invoice> SortByPartDescription(IEnumerable<Invoice> invoices)
        {
            return invoices.OrderBy(x => x.PartDescription);
        }

        private static IEnumerable<Invoice> SortByPrice(IEnumerable<Invoice> invoices)
        {
            return invoices.OrderBy(x => x.Price);
        }

        private static IEnumerable<object> SelectDescriptionQuantity(IEnumerable<Invoice> invoices)
        {
            return invoices
                .Select(x => new
                {
                    x.PartDescription,
                    x.Quantity
                })
                .OrderBy(x => x.Quantity);
        }

        private static IEnumerable<string> SelectDescriptionValue(IEnumerable<Invoice> invoices)
        {
            return invoices
                .Select(x => new
                {
                    x.PartDescription,
                    InvoiceTotal = x.Quantity * x.Price
                })
                .OrderBy(x => x.InvoiceTotal)
                .Select(x => x.ToString());
        }

        private static IEnumerable<Invoice> GetInvoicesBetween200And500(IEnumerable<Invoice> invoices)
        {
            return invoices
                .Where(x => x.Price > 200 && x.Price < 500);
        }
    }
}
