fn power_rec(a: u64, b: i32) -> u64
{
    if b < 0
    {
        return 0;
    }
    else if b < 1
    {
        return 1;
    }
    a * power_rec(a, b - 1)
}

fn main()
{
    let mut input: String = String::new();

    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let a: u64 = input.trim().parse().expect("Incorrect parse");

    input.clear();

    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let b: i32 = input.trim().parse().expect("Incorrect parse");
    if b < 0
    {
        panic!("Incorrect input data");
    }
    if b == 1
    {
        println!("Result is: {}", a);
        return;
    }

    println!("Result is: {}", power_rec(a, b));
}
