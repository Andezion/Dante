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

    if size < 1 {
        println!("Not enough data available");
    }
    if size > 100 {
        size = 100;
    }

    input.clear();
    std::io::stdin().read_line(&mut input).expect("Error");
    let number: i32 = input.trim().parse().expect("Error");

    println!();

    let mut sum1: i32 = 0;
    let mut sum2: i32 = 0;

    for i in 0..size {
        if number > vector[i] {
            sum1 += 1;
        }
        if number < vector[i] {
            sum2 += 1;
        }
    }

    println!("{} {}", sum1, sum2);
}
