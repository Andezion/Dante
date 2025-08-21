fn main() {
    let mut input: String = String::new();

    let mut vector: [i32; 1000] = [0; 1000];
    let mut size: usize = 0;

    println!("Enter: ");

    for i in 0..2000 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        vector[size] = input.trim().parse().expect("Error");

        if vector[size] == 0 {
            break;
        }

        size += 1;
    }

    let mut vector2: [i32; 1000] = [0; 1000];
    let mut size2: usize = 0;

    println!("Enter: ");

    for i in 0..2000 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        vector2[size2] = input.trim().parse().expect("Error");

        if vector2[size2] == 0 {
            break;
        }

        size2 += 1;
    }

    if size > 100 {
        size = 100;
    }
    if size < 2 {
        panic!("Not enough data available");
    }
    if size2 == 0 || size != 2{
        panic!("Not enough data available");
    }

    let mut counter: i32 = 0;
    for i in 0..size - 1 {
        if vector[i] == vector2[0] {
            if vector[i + 1] == vector2[1] {
                counter += 1;
            }
        }
    }

    println!("{}", counter);

    for i in 0..size - 1 {
        if vector[i] == vector2[0] {
            if vector[i + 1] == vector2[1] {
                println!("\n{}", i);
            }
        }
    }
}
