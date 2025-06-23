fn main()
{
    println!("Enter number: ");

    let mut number = String::new();
    std::io::stdin().read_line(&mut number).expect("Failed to read line");
    let number: f64 = number.trim().parse().expect("Please type a number");
    
    println!("{:.2}\n{:.2}", number + 273.15, (number * 9.0 / 5.0) + 32.0);

    return;
}
