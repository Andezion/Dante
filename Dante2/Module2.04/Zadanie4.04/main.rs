fn create_array_int(ptr: &mut Option<Vec<i32>>, n: usize) -> i32 {
    if n == 0 {
        return 1;
    }

    let array: Vec<i32> = Vec::with_capacity(n);

    *ptr = Some(array);

    0
}


fn main() {
    let mut input: String = String::new();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let size: usize = input.trim().parse().expect("Incorrect parsing");

    let mut array: Option<Vec<i32>> = None;
    let result = create_array_int(&mut array, size);
    if result == 1 {
        panic!("");
    }

    let mut array = array.unwrap();

    println!("Enter: ");

    for _i in 0..size {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let number: i32 = input.trim().parse().expect("Error!");
        array.push(number);
    }

    for i in 0..array.len() {
        print!("{} ", array[i]);
    }
}
