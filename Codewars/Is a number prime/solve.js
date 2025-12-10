//O(n) time complexity

// function isPrime(num)
// {
//     if (num <= 1) return false;
//     for (let i = 2; i < num; i++)
//     {
//         if (num % i === 0) return false;
//     }
//     return true;
// }

//O(sqrt(n)) 
function isPrime(num) {
    if (num <= 1) return false;
    for (let i = 2; Math.sqrt(num) >= i; i++) {
        if (num % i === 0) return false;
    }
    return true;
}

isPrime(11);
console.log(isPrime(11)); // true
isPrime(4);
console.log(isPrime(4)); // false