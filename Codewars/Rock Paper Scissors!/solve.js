const winsAgainst = {
    rock: 'scissors',
    paper: 'rock',
    scissors: 'paper'
};

// determine the game rule
function rps(p1, p2) {
    if (p1 === p2) {
        return 'Draw!';
    } else if (winsAgainst[p1] === p2) {
        return 'Player 1 won!';
    } else {
        return 'Player 2 won!';
    }
}

console.log(rps('scissors', 'paper')); 
console.log(rps('scissors', 'rock'));  
console.log(rps('paper', 'paper')); 
