fn main() {
    let mut array: Vec<i32> = Vec::new();

    for i in 0..100 {
        array.push(i);
        print!("{} ", array[i as usize]);
    }
}
