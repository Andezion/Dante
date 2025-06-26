fn main()
{
    let mut counter: i32 = 0;

    println!("Enter: ");
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Error");
    let number: i32 = input.trim().parse().expect("Error");
    
    for i in 1 .. number + 1
    {
        if number % i == 0
        {
            counter += 1;
        }
    }
    
    if counter == 2
    {
        print!("YES");
    }
    else
    {
        print!("NO");
    }
    
    return;
}
