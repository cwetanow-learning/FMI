namespace Linq.Tasks
{
    public class Invoice
    {
        private int quantityValue;
        private decimal priceValue;
        public Invoice(int part, string description,
           int count, decimal pricePerItem)
        {
            this.PartNumber = part;
            this.PartDescription = description;
            this.Quantity = count;
            this.Price = pricePerItem;
        }

        public int PartNumber { get; set; }

        public string PartDescription { get; set; }

        public int Quantity
        {
            get
            {
                return this.quantityValue;
            }
            set
            {
                if (value > 0)
                {
                    this.quantityValue = value;
                }
            }
        }

        public decimal Price
        {
            get
            {
                return this.priceValue;
            }
            set
            {
                if (value >= 0M)
                {
                    this.priceValue = value;
                }
            }
        }

        public override string ToString()
        {
            return $"{this.PartNumber,-5} {this.PartDescription,-20} {this.Quantity,-5} {this.Price,6:C}";
        }
    }
}
