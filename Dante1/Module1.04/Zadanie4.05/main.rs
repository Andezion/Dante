fn main()
{
    let mut array:[f32; 10] = [0.0; 10];
    
    println!("Enter numbers: ");
    
    for i in 0..10
    {
        let mut input: String = String::new();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let input: f32 = input.trim().parse().expect("Incorrect number");
        
        array[i] = input;
    }
    
    for i in 0..10
    {
        println!("{:.2} ", array[i]);
    }
    
    return;
}
