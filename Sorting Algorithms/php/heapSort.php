<?php

echo "Original array:\n";
$size = rand(1,20);
$array = array();
for($i = 0; $i < $size; $i++){
    $rand = rand(1,100);
    array_push($array, $rand);
}
print_r($array);

$sortedArray = heapSort($array);
echo "Sorted array:\n";
print_r($sortedArray);

function heapSort($array): array
{
    $sizeArray = count($array);
    $init = (int) floor((count($array) / 2 - 1));

    for ($i = $init; $i >= 0; $i--) {
        buildHeap($array, $sizeArray, $i);
    }

    for ($i = $sizeArray - 1; $i >= 0; $i--) {
        $swap = $array[0];
        $array[0] = $array[$i];
        $array[$i] = $swap;

        buildHeap($array, $i, 0);
    }

    return $array;
}

function buildHeap(&$array, $heapSize, $node)
{
    $left = 2 * $node + 1;
    $right = 2 * $node + 2;
    $max = $node;

    do {
        if ($left < $heapSize && $array[$left] > $array[$max]) {
            $max = $left;
        }

        if ($right < $heapSize && $array[$right] > $array[$max]) {
            $max = $right;
        }

        if ($max != $node) {
            $swap = $array[$node];
            $array[$node] = $array[$max];
            $array[$max] = $swap;

            $left = 2 * $max + 1;
            $right = 2 * $max + 2;
            $node = $max;
        } else {
            break;
        }

        if ($left >= $heapSize || $right >= $heapSize) {
            break;
        }
    } while ($array[$left] > $array[$max] || $array[$right] > $array[$max]);
}
?>