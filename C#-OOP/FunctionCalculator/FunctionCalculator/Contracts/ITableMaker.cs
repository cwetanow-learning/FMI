using System.Collections.Generic;

namespace FunctionCalculator.Contracts
{
    public interface ITableMaker
    {
        IList<string> MakeTable(double start, double end, double steps);
    }
}
