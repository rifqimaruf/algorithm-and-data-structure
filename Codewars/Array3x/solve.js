function explode(x){
    let score = 0;
    if (typeof x[0] === 'number') score += x[0];
    if (typeof x[1] === 'number') score += x[1];
    if (typeof x[0] !== 'number' && typeof x[1] !== 'number') return "Void!";
    return Array.from({ length: score }, () => [...x]);
}

// Example 
console.log(explode([3, 5]));
console.log(explode([3, 'a']));
console.log(explode(['b', 5]));
console.log(explode(['a', 'b']));
console.log(explode([5, -5]));


// today i learn about spread sytax, mudahnya dia menguraikan elemen dari sebuah iterable
const arr = [1, 2, 3];
const newArr = [...arr, 4, 5]; 
console.log(newArr); 