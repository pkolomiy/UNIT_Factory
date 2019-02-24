namespace ExpertSystem.Models
{
    public class Fact
    {
        public bool? Value { get; set; }

        public Fact()
        {
        }

        public Fact(bool value)
        {
            Value = value;
        }
    }
}
