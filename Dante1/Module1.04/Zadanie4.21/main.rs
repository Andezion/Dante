fn is_prime(n: i32) -> i32 {
    if n <= 1 {
        return 0;
    }

    for i in 2..=i32::isqrt(n)  {
        if n % i == 0 {
            return 0;
        }
    }

    1
}

fn main() {
    let mut input: String = String::new();

    let mut vector: [i32; 200] = [0; 200];
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

    if size == 0 {
        panic!("Not enough data available");
    }

    let mut found: u8 = 0;
    for i in (0..size - 1).rev() {
        if is_prime(i as i32) == 1 {
            println!("{} ", vector[i]);
            found = 1;
        }
    }

    if found == 0 {
        println!("Nothing to show");
    }
}
