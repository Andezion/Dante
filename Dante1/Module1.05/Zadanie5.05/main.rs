fn main()
{
    let storage: &str = "aeuioAEUIO";
    let mut input:String = String::new();

    println!("Enter smth: ");
    std::io::stdin().read_line(&mut input).expect("Failed to read line");
    
    let mut counter: i32 = 0;
    for letter in input.chars()
    {
        if storage.contains(letter)
        {
            counter += 1;
        }
    }
    
    println!("Result is: {}.", counter);
}
