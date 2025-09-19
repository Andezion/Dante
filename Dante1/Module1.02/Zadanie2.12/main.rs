fn main() {
    let mut input = String::new();

    std::io::stdin().read_line(&mut input).expect("Err");
    println!("Enter: ");
    let mut a: i32 = input.trim().parse().expect("Err");

    input.clear();

    std::io::stdin().read_line(&mut input).expect("Err");
    println!("Enter: ");
    let mut b: i32 = input.trim().parse().expect("Err");

    input.clear();

    std::io::stdin().read_line(&mut input).expect("Err");
    println!("Enter: ");
    let mut c: i32 = input.trim().parse().expect("Err");

    if a == 0 && b == 0 && c == 0 {
        panic!("Endless");
    }

    if a == 0 && b == 0 {
        panic!("none");
    }

    if a == 0 {
        println!("Jeden: {}", -c / b);
    }

    let disc = b * b - 4 * a * c;
    if disc == 0 {
        println!("Jeden: {}", -b / (2 * a));
    }
    else if disc < 0 {
        panic!("none")
    }
    println!("Dwa: {}, {}", (-b + i32::isqrt(disc)) / (2 * a), (-b - i32::isqrt(disc)) / (2 * a))
}
