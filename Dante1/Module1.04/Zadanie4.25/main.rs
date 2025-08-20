fn main() {
    let mut input: String = String::new();

    let mut vector: [i32; 100] = [0; 100];
    let mut size: usize = 0;

    println!("Enter: ");

    for i in 0..200 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        vector[size] = input.trim().parse().expect("Error");

        if vector[size] == 0 {
            break;
        }

        size += 1;
    }

    let mut vector2: [i32; 100] = [0; 100];
    let mut size2: usize = 0;

    if size < 1 {
        println!("Enter: ");

        for i in 0..200 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Error");
            vector2[size2] = input.trim().parse().expect("Error");

            if vector2[size2] == 0 {
                break;
            }

            size2 += 1;
        }
    }
    if size > 100 {
        size = 100;
    }


    println!("Enter: ");

    for i in 0..200 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        vector2[size2] = input.trim().parse().expect("Error");

        if vector2[size2] == 0 {
            break;
        }

        size2 += 1;
    }

    if size2 < 1
    {
        panic!("Not enough data available");
    }
    if size2 > 100 {
        size2 = 100;
    }

    let mut pointer: u8 = 0;

    for i in 0..size2 - 1 {
        for j in i + 1..size2 {
            if vector2[i] == vector[j] {
                let mut point: u8 = 0;

                for n in 0..size {
                    if vector[n] == vector2[i] {
                        point = 1;
                    }
                }

                if point == 0 {
                    print!("{} ", vector2[i]);
                    pointer = 1;
                    break;
                }
            }
        }
    }

    if pointer == 0 {
        print!("Nothing to show");
    }
}
