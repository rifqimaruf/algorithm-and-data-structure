using System;

public class Kata
{
    public static bool Validate_hello(string greetings)
    {
        if (greetings == null) return false;
        string[] greet = { "hello", "ciao", "salut", "hallo", "hola", "ahoj", "czesc" };

        greetings = greetings.ToLower();

        foreach (string word in greet)
        {
            if (greetings.Contains(word))
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
