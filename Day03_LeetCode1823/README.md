# Find the winner of the cycle game

[Sorce](https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08)

## Problem

We have a circle of friends numbered from 1 to n. The game starts with the first friend. In each round, we count k friends in the clockwise direction (including the friend we started with). The last friend counted leaves the circle, and we repeat the process with the next friend clockwise. This continues until only one friend remains, who wins the game.

Example 1:

> -   Input: n = 5, k = 2
>     Output: 3
>     Explanation: Here are the steps of the game:
>
> 1. Start at friend 1.
> 2. Count 2 friends clockwise, which are friends 1 and 2.
> 3. Friend 2 leaves the circle. Next start is friend 3.
> 4. Count 2 friends clockwise, which are friends 3 and 4.
> 5. Friend 4 leaves the circle. Next start is friend 5.
> 6. Count 2 friends clockwise, which are friends 5 and 1.
> 7. Friend 1 leaves the circle. Next start is friend 3.
> 8. Count 2 friends clockwise, which are friends 3 and 5.
> 9. Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.

## Approach

The key insight is that we can simulate the game using recursion.

1. Base Case:
    - If there is only on friend left then that friend winds, and we retrun 0;
2. Recursive Step:
    - We recursively call the function `findTheWinner` with n-1 friends(since one friend has left the circle).
    - We add _k_ to the result of the recursive call(to accoutn for the clockwisec counting)
    - Lastly, we take the result modulo n to ensure that the counting wraps around the cirlce.

## Reference

[CodeHelp -by Babbar](https://www.youtube.com/watch?v=gAZwWpv_GUM)
