<?php

$array = array(8,1,2,5,6,7);
print_array($array);
merge_sort($array);
print_array($array);

function merge_sort(&$list){
    if( count($list) <= 1 ){
        return $list;
    }

    $left =  array();
    $right = array();

    $middle = (int) ( count($list)/2 );

    // Make left
    for( $i=0; $i < $middle; $i++ ){
        $left[] = $list[$i];
    }

    // Make right
    for( $i = $middle; $i < count($list); $i++ ){
        $right[] = $list[$i];
    }

    // Merge sort left & right
    merge_sort($left);
    merge_sort($right);

    // Merge left & right
    return merge($left, $right);
}

function merge(&$left, &$right){
    $result = array();

    while(count($left) > 0 || count(right) > 0){
        if(count($left) > 0 && count(right) > 0){
            if($left[0] <= $right[0]){
                $result[] = array_shift($left);
            } else {
                $result[] = array_shift($right);
            }
        } elseif (count($left) > 0){
            $result[] = array_shift($left);
        } elseif (count($right) > 0){
            $result[] = array_shift($right);
        }
    }

    print_array($result);exit;

    return $result;
}

function print_array($array){
    echo "<pre>";
    print_r($array);
    echo "<br/>";
    echo "</pre>";
}

?
