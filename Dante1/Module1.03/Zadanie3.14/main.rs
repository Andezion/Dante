fn main()
{
    let mut sum: f32 = 0.0;

    let mut max_value: f32 = -1000.0;
    let mut min_value: f32 = 1000.0;

    for mut _i in 0..101
    {
        println!("Enter: ");
        
        let mut input: String = String::new();
        std::io::stdin().read_line(&mut input).expect("Incorrect input string");
        let input: f32 = input.trim().parse(). expect("Error in parsing variable");
        
        sum = sum + input;

        if max_value < input
        {
            max_value = input;
        }
        
        if min_value > input
        {
            min_value = input;
        }
        
        _i = _i + 1;
    }
    
    println!("\
    Min is: {}\n\
    Max is: {}\n\
    Avg is: {}",
    min_value, max_value, sum / 100.0);

    return;
}
