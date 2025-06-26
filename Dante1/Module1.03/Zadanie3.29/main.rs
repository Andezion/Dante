use rand::random_range;

fn main()
{
    let number_to_find: i32 = random_range(0 .. 101);
    
    let mut input: String = String::new();

    loop 
    {
        input.clear();
        
        println!("Enter: ");
        std::io::stdin().read_line(&mut input).expect("Error");
        let user_number: i32 = input.trim().parse().expect("Error");
        
        if user_number > number_to_find
        {
            println!("Too much");
        }
        else if user_number < number_to_find
        {
            println!("Too few");
        }
        else
        {
            println!("You win!");
            break;
        }
    }
}
