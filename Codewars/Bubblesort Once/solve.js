function bubblesortOnce(arr)
{
    let arrnew = arr.slice();
    let n = arrnew.length;
    for (let i = 0; i < n - 1; i++) 
        {
            if(arrnew[i] > arrnew[i+1]) 
            {
                let temp = arrnew[i];
                arrnew[i] = arrnew[i+1];
                arrnew[i+1] = temp;
            }
        }
   
    return arrnew;
}

// examples
console.log(bubblesortOnce([9, 7, 5, 3, 1, 2, 4, 6, 8]));

