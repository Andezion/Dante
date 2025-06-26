fn main()
{
    let end: &str = "a";
    let mut input: String = String::new();
    
    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error while reading string");
    let input = input.trim();
    
    if input.ends_with(end) == true
    {
        println!("Woman");
    }
    else
    {
        println!("Man");
    }
}
