fn helper(num: usize) -> u32
{
    let mut counter: i32 = 0;
    
    for i in 1..num + 1
    {
        if num % i == 0
        {
            counter = counter + 1;
        }
    }
    
    if num <= 0
    {
        return 0;
    }
    
    if num != 1
    {
        if counter <= 2
        {
            return 1;
        }
        else 
        { 
            return 2;    
        }
    }
    
    0
}

fn main()
{
    let mut array:[usize; 10] = [0; 10];
    
    println!("Enter: ");
    
    let mut input: String = String::new();
    
    let mut i: usize = 0;
    while i < 10
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect string input");
        let number_one: usize = input.trim().parse().expect("Incorrect number");
        array[i] = number_one;
        i = i + 1;
        
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect string input");
        let number_two: usize = input.trim().parse().expect("Incorrect number");
        array[i] = number_two;
        i = i + 1;
    }
    
    for i in 0..10
    {
        if helper(array[i]) == 1
        {
            println!("{} - is prime", array[i]);
        }
        else if helper(i) == 2
        {
            println!("{} - is composite", array[i]);
        }
        else 
        {
            println!("{} - is other", array[i]);
        }
    }
    
    return;
}
