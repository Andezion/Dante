fn main()
{
    let mut array:[i32; 3000] = [0; 3000];
    let mut size_of_array: usize = 0;
    
    println!("Enter: ");
    let mut input: String = String::new();
    
    for _i in 0 .. 3000
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Error");
        let number: i32 = input.trim().parse().expect("Error");
        
        if number == 0
        {
            break;
        }
        
        array[size_of_array] = number;
        size_of_array += 1;
    }
    
    if size_of_array > 1000
    {
        size_of_array = 1000;
    }
    
    if size_of_array == 0 || size_of_array == 1
    {
        println!("{}\n{}\n", 0 ,0);
        return;
    }
    
    let mut max: i32 = i32::MIN;
    let mut counter: i32 = 0;
    let mut temp: i32 = 1;
    
    let mut some_shit:[i32; 1000] = [0; 1000];
    let mut storage_for_index:[i32; 1000] = [0; 1000];
    
    for i in 1 .. size_of_array
    {
        if array[i] > array[i - 1]
        {
            temp += 1;
        }
        else
        {
            if temp > max
            {
                max = temp;
                
                counter = 1;
                some_shit[0] = temp;
                storage_for_index[0] = i as i32 - temp;
            }
            else if temp == max
            {
                some_shit[counter as usize] = temp;
                storage_for_index[counter as usize] = i as i32 - temp;
                counter += 1;
            }
            temp = 1;
        }
    }

    if temp > max
    {
        max = temp;
        counter = 1;
        some_shit[0] = temp;
        storage_for_index[0] = size_of_array as i32 - temp;
    }
    else if temp == max
    {
        some_shit[counter as usize] = temp;
        storage_for_index[counter as usize] = size_of_array as i32 - temp;
        counter += 1;
    }
    if max < 2
    {
        println!("\n0\n0\n");
        return;
    }

    println!("{}\n{}", max, counter);
    for i in 0 .. counter
    {
        print!("{} -", storage_for_index[i as usize]);
        for j in 0 .. some_shit[i as usize]
        {
            print!(" {}", array[(storage_for_index[i as usize] + j) as usize]);
        }
        println!();
    }
    
    return;
}
