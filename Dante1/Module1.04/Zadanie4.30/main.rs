fn main() {
    let mut input: String = String::new();

    let mut size_one: usize = 0;
    let mut array_one:[i32; 100] = [0; 100];
    println!("Enter: ");

    for _i in 0..100 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        array_one[size_one] = input.trim().parse().expect("Incorrect parsing");
        if array_one[size_one] == 0 {
            break;
        }
        size_one += 1;
    }

    let mut size_two: usize = 0;
    let mut array_two:[i32; 100] = [0; 100];
    println!("Enter: ");

    for _i in 0..100 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        array_two[size_two] = input.trim().parse().expect("Incorrect parsing");
        if array_two[size_two] == 0 {
            break;
        }
        size_two += 1;
    }

    for i in 0..100 {
        let mut counter: i32 = 0;
        for j in 0..100 {
            if array_one[size_one] < array_two[size_two] {
                counter += 1;
            }
        }
        print!("{} ", counter);
    }
}
