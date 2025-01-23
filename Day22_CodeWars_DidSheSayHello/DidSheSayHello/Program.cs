using System;

    public class Kata
    {
        public static bool Validate_hello(string greetings)
        {
            if (greetings == null) return false;
            greetings = greetings.ToLower();
            string[] hello = {"hello", "ciao", "salut", "hallo", "hola", "ahoj", "czesc", "ahoj!", "hallo, wie geht's dir?", "hombre! hola!", "hallo, salut", "salut", "ciao bella!"};  
            foreach (string word in hello)
            {
                if (greetings == word)
                {
                    return true;
                }
            }
            return false;
        }
    }

public class Program
{
    public static void Main()
    {
        string input = Console.ReadLine();
        bool result = Kata.Validate_hello(input);
        Console.WriteLine(result);
    }
}