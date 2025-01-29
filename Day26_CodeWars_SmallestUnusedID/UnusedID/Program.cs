using System;

public class Kata
{
  public static int NextId(int[] ids)
  {
    Array.Sort(ids);
    Console.WriteLine(string.Join(", ", ids));
    for (int i = 0; i < ids.Length; i++)
    {
      if (ids[i] != i)
      {
        return i;
      }
    }
    return ids.Length;
  }
}

public class Program
{
    public static void Main(string[] args)
    {
        Console.WriteLine(Kata.NextId(new int[] {0, 1, 2, 3, 5}));
        Console.WriteLine(Kata.NextId(new int[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    }
}