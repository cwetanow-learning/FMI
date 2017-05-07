namespace DiagramStuff.Models
{
    public class Invoice
    {
        private string partDescription;
        private string partNumber;
        private int quantity;
        private decimal price;

        public Invoice(string description, string number, int quantity, decimal price)
        {
            this.PartDescription = description;
            this.PartNumber = number;
            this.Quantity = quantity;
            this.Price = price;
        }

        public string PartDescription
        {
            get
            {
                return this.partDescription;
            }
            set
            {
                this.partDescription = value;
            }
        }

        public string PartNumber
        {
            get
            {
                return this.partNumber;
            }
            set
            {
                this.partNumber = value;
            }
        }

        public int Quantity
        {
            get
            {
                return this.quantity;
            }
            set
            {
                this.quantity = value;
            }
        }

        public decimal Price
        {
            get
            {
                return this.price;
            }
            set
            {
                this.price = value;
            }
        }

        public decimal GetInvoiceAmount()
        {
            var amount = this.Quantity * this.Price;
            return amount;
        }
    }
}
