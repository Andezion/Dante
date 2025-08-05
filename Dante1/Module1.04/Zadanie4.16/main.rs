fn main() {
    let mut array: [i32; 1000] = [0; 1000];
    let mut size: usize = 0;

    let mut input: String = String::new();

    for i in 0..1000 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        array[size] = input.trim().parse().expect("Error");

        if array[size] == 0 {
            break;
        }

        size += 1;
    }

    if size < 2 {
        panic!("Not enough data available");
    }

    if size % 2 == 0 {
        for i in 1..size / 2 + 1 {
            println!("{} ", array[size - i] - array[i - 1]);
        }
    }
    else {
        for i in 1..size / 2 + 1 {
            println!("{} ", array[size - i] - array[i - 1]);
        }
        println!("{}", array[size / 2]);
    }
}
