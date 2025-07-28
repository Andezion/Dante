fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Err");
    let num1: i32 = input.trim().parse().expect("err");

    input.clear();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Err");
    let num2: i32 = input.trim().parse().expect("err");

    println!("{}", num1 + num2);
    println!("{}", num1 - num2);
    println!("{}", num1 * num2);

    if num2 == 0 {
        panic!("Operation is not permitted");
    }
    else {
        println!("{}", num1 / num2);
    }
}
