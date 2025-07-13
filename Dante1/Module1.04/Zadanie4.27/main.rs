fn main() {
    let mut array:[i32; 100] = [0; 100];
    let mut size: usize = 0;

    let mut max: i32 = i32::MIN;
    let mut min: i32 = i32::MAX;

    let mut max_i: i32 = 0;
    let mut min_i: i32 = 0;

    let mut input: String = String::new();
    println!("Enter: ");
    for i in 0..100 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");

        array[i] = input.trim().parse().expect("Incorrect parse");

        if array[i] == 0 {
            break;
        }

        size += 1;

        if array[i] > max {
            max = array[i];
            max_i = i as i32;
        }

        if array[i] < min {
            min = array[i];
            min_i = i as i32;
        }
    }

    if size < 2 {
        panic!("Not enough data available");
    }

    print!("Result is: {}", array[((max_i + min_i) / 2) as usize]);
}
