
fn main() {
    let mut array = vec![10, 4, 8, 4, 9, 4, 0];
    println!("Using vector: {:?}", array);

    bubble_sort(array.as_mut());
    println!("Sorted: {:?}", array);

}


fn bubble_sort(vector: &mut Vec<i32>) {
    let vector_size = vector.len();
    for _ in 0..vector_size {
        for i in 1..vector_size {
            if vector[i] < vector[i-1] {
                let temp = vector[i];
                vector[i] = vector[i-1];
                vector[i-1] = temp;
            }
        }
    }
}