use std::cmp::{max, min};

fn main() {
    let mut array:[i32; 10] = [0; 10];
    let mut maximum: i32 = i32::MAX;
    let mut minimum: i32 = i32::MIN;

    let mut input: String = String::new();
    println!("Enter: ");

    let mut sum: i32 = 0;
    for i in 0..10 {
        input.clear();

        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        array[i] = input.trim().parse().expect("Incorrect parse");

        sum = sum + array[i];
        maximum = max(maximum, array[i]);
        minimum = min(minimum, array[i]);
    }

    println!("{} {} {}", sum as f32 / 10.0, maximum, minimum);
}
