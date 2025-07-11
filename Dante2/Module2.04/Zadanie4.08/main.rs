mod custom_array;

fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let size: usize = input.trim().parse().expect("Incorrect parse");

    let mut a: custom_array::ArrayT = custom_array::array_create_struct(size);

    loop {
        println!("Enter: ");

        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let choice: u8 = input.trim().parse().expect("Incorrect parse");

        if choice == 1 {
            let mut counter: usize = 0;
            loop {
                input.clear();
                std::io::stdin().read_line(&mut input).expect("Incorrect input");
                let number: i32 = input.trim().parse().expect("Error!");

                if counter >= a.capacity {
                    println!("Buffer is full!!");
                }
                if number == 0 || counter == a.capacity {
                    break;
                }
                if number != 0 {
                    match custom_array::array_push_back(&mut a, number) {
                        1 => panic!("Incorrect input data"),
                        2 => break,
                        _other => counter += 1,
                    }
                }

                if a.size == 0 {
                    panic!("Buffer is empty");
                }
            }

        }
        else if choice == 2 {
            println!("Enter: ");
            loop {
                input.clear();
                std::io::stdin().read_line(&mut input).expect("Incorrect input");
                let number: i32 = input.trim().parse().expect("Error!");

                if number == 0 {
                    break;
                }
                custom_array::array_remove_item(&mut a, number);
            }

            if a.size != 0 {
                custom_array::array_display(&a);
            }
            else {
                println!("Buffer is empty");
            }
        }
        else if choice == 0 {
            break;
        }
        else {
            panic!("Incorrect number: ");
        }
    }
}
