<?php 
// A Dynamic Programming solution for 
// Rod cutting problem 
  
/* Returns the best obtainable price  
for a rod of length n and price[] as 
prices of different pieces */
function cutRod( $price, $n) 
{ 
    $val = array(); 
    $val[0] = 0; 
    $i; $j; 
      
    // Build the table val[] in bottom  
    // up manner and return the last 
    // entry from the table 
    for ($i = 1; $i <= $n; $i++) 
    { 
        $max_val = PHP_INT_MIN; 
          
        for ($j = 0; $j < $i; $j++) 
            $max_val = max($max_val,  
             $price[$j] + $val[$i-$j-1]); 
        $val[$i] = $max_val; 
    } 
      
    return $val[$n]; 
} 
  
// Driver program to test above functions 
$arr = array(1, 5, 8, 9, 10, 17, 17, 20); 
$size = count($arr); 
echo "Maximum Obtainable Value is ",  
                      cutRod($arr, $size); 
      
// This code is contributed by anuj_67. 
?> 
