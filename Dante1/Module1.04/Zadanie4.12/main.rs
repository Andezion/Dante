fn main()
{
    let mut array:[i32; 1000] = [0; 1000];
    let mut iterator: usize = 0;
    
    let mut sum: f32 = 0.0;
    
    let mut input: String = String::new();
    
    println!("Enter: ");
    
    while iterator != 1000
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        let number: i32 = input.trim().parse().expect("Error");
        
        if number == 0
        {
            break;
        }
        
        array[iterator] = number;
        sum += number as f32;
        iterator += 1;
    }
    
    if iterator < 1
    {
        panic!("Nothing to show");
    }
    
    let mut sum_more_than_middle: i32 = 0;
    let mut sum_less_than_middle: i32 = 0;
    
    let middle: f32 = sum / iterator as f32;
    
    for i in 0 .. iterator
    {
        if array[i] as f32 > middle
        {
            sum_more_than_middle += array[i];
        }
        
        if middle > array[i] as f32
        {
            sum_less_than_middle += array[i];
        }
    }
    
    println!("{:.2}\n{}\n{}", middle, sum_more_than_middle, sum_less_than_middle);
    
    return;
}
