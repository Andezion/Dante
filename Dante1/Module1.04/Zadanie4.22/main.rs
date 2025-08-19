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
    
    if size >= size2 {
        for i in 0..size2 {
            print!("{} ",vector[i] - vector2[i]);
        }
    }
    else {
        for i in 0..size {
            print!("{} ",vector[i] - vector2[i]);
        }
    }
}
