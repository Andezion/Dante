fn main()
{
    println!("Enter two numbers: ");

    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");

    let mut input = input.trim().split_whitespace();

    let num1: i32 = input.next().expect("Too few arguments").parse().expect("Incorrect number");
    let num2: i32 = input.next().expect("Too few arguments").parse().expect("Incorrect number");
    
    println!("Result is: {}", num1 + num2);

    return;
}
