fn main()
{
    println!("Enter number: ");
    let mut number_one: String = String::new();
    std::io::stdin().read_line(&mut number_one).expect("Incorrect input");
    let mut number_one: f32 = number_one.trim().parse().expect("Incorrect parsing");

    if number_one < 0.0
    {
        panic!("Incorrect input");
    }

    println!("Enter: ");
    let mut number_two: String = String::new();
    std::io::stdin().read_line(&mut number_two).expect("Incorrect input");
    let number_two: i32 = number_two.trim().parse().expect("Incorrect parsing");

    if number_two < 0
    {
        panic!("Incorrect input");
    }

    for _i in 0..number_two
    {
        number_one = number_one + number_one * 0.01;
    }

    println!("Result is: {:.2}", number_one);

    return;
}
