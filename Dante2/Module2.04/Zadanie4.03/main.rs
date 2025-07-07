fn create_array(size: i32) -> Vec<i32> {
    if size <= 0 {
        panic!("Incorrect input");
    }

    vec![0; size as usize]
}
fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let number: i32 = input.trim().parse().expect("Incorrect parse");

    if number <= 0 {
        panic!("Incorrect input data");
    }

    let mut array: Vec<i32> = create_array(number);

    print!("Enter: ");
    for i in 0..array.len()
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let num: i32 = input.trim().parse().expect("Incorrect parse");
        array[i] = num;
    }

    for i in (0..number).rev() {
        print!("{} ", array[i as usize]);
    }
}
