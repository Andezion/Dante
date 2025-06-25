fn main()
{
    let mut array_one:[i32; 100] = [0; 100];
    let mut size_of_array_one: usize = 0;
    
    println!("Enter: ");
    
    let mut input: String = String::new();
    
    for _i in 0 .. 101
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let number: i32 = input.trim().parse().expect("Incorrect number");
        
        if number == 0
        {
            break;
        }
        
        array_one[size_of_array_one] = number;
        size_of_array_one += 1;
    }
    
    let mut array_two:[i32; 100] = [0; 100];
    let mut size_of_array_two: usize = 0;
    
    if size_of_array_one < 1
    {
        println!("Enter: ");
        
        for _i in 0 .. 101
        {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect input");
            let number: i32 = input.trim().parse().expect("Incorrect number");
            
            if number == 0
            {
                break;
            }
            
            array_two[size_of_array_two] = number;
            size_of_array_two += 1;
        }
        
        panic!("Not enough data available");
    }
    
    println!("Enter: ");
    for _i in 0 .. 101
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let number: i32 = input.trim().parse().expect("Incorrect number");

        if number == 0
        {
            break;
        }

        array_two[size_of_array_two] = number;
        size_of_array_two += 1;
    }
    
    if size_of_array_two < 1
    {
        panic!("Not enough data available");
    }
    
    let mut temp: u8 = 0;
    
    for _i in 0 .. size_of_array_one
    {
        for _j in 0 .. size_of_array_two
        {
            if array_one[_i] == array_two[_j]
            {
                let mut helper: u8 = 0;
                
                for _k in 0 .. _i
                {
                    if array_one[_k] == array_one[_i]
                    {
                        helper = 1;
                        break;
                    }
                }
                
                if helper == 0
                {
                    println!("{} ", array_one[_i]);
                    temp = 1;
                }
                
                break;
            }
        }
    }
    
    if temp == 0
    {
        println!("Nothing to show");
    }
    return;
}
