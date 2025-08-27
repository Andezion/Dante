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

    for i in 0..size_one - 1 {
        let mut index: i32 = array_one[i];
        if index < 0 {
            index = 0;
        }
        else if index as usize >= size_two {
            index = (size_two - 1) as i32;
        }

        print!("{} ", array_two[index as usize]);
    }
}
