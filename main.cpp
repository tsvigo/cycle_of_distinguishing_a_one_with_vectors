#include <QCoreApplication>// минимально воспроизводимый код
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned long long> list_of_synapses ;
std::vector<unsigned long long> list_of_neurons ;
long long variable_error;
int var ;
int neuron_index, synapse_index;
int variable_synapse_index_counter=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    std::ifstream is(
//        "/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/neurons_and_signal.txt"
//        );
//    std::istream_iterator<unsigned long long> start(is), end;
//    std::vector<unsigned long long> list_of_neurons(start, end);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//std::cout << "variable_error = " << variable_error<< std::endl; // тут ошибка 0
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    try {
        
        
        unsigned long long n;    
        // std::vector<int>list_neyronov;
        ifstream file("/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/neurons_and_signal.txt");
        if (!file) {
            std::cerr << "ERROR: Cannot open "
                         "'/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/neurons_and_signal.txt'!"
                      << std::endl;
            exit(1);
        }
        while (!file.eof()) 
        {        file >> n;        list_of_neurons.push_back(n);     //   cout << n << endl;
        } 
        file.close();
        //   std::cout << list_neyronov[200] << std::endl;
        
    }
    catch (const std::exception &ex) {
        std::cerr << "Exception: '" << ex.what() << "'!" << std::endl;
        exit(1);
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    std::ifstream is2("/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/synapses.txt");
//    std::istream_iterator<unsigned long long> start2(is2), end2;
//    std::vector<unsigned long long> list_of_synapses(start2, end2);
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    try {
        
        
        unsigned long long n;    
       
        ifstream file("/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/synapses.txt");
        if (!file) {
            std::cerr << "ERROR: Cannot open "
                         "'/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/synapses.txt'!"
                      << std::endl;
            exit(1);
        }
        while (!file.eof()) 
        {        file >> n;        list_of_synapses.push_back(n);     //   cout << n << endl;
        } 
        file.close();
       
        
    }
    catch (const std::exception &ex) {
        std::cerr << "Exception: '" << ex.what() << "'!" << std::endl;
        exit(1);
    }    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    
//    variable_error     =   1073741824-list_of_neurons[200] ;
//    // если ошибки нет то на выход
//    if (variable_error<=0)
//    goto d;
    
     std::cout << "variable_error = " << variable_error<< std::endl;
    std::cout << "Variable error = 1073741824-list_of_neurons[200] = " << "1073741824 - " << list_of_neurons[200]<< std::endl;
     std::cout << "list_of_neurons[200]  = " << list_of_neurons[200]  << std::endl;
        // если ошибки нет то на выход
//        if (variable_error<=0) // закомментируем на первый проход
//        goto d;
    b:
////////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
        for ( var = 100; var < 200; ++var) // This is the range of neurons
        {
    for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200, synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)
 
           {
                
                    list_of_neurons[var]=list_of_neurons[var]+  (list_of_neurons[neuron_index]/ list_of_synapses[synapse_index]);    
            }
        }
        
        for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
        {
            list_of_neurons[200] = list_of_neurons[200] + (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]);
            // NOTE: непонятно каким должно быть значение 200 нейрона при первом проходе. <1073741824?
            // Если файл 201.txt существует то 200 нейрон брать из него а если не существует то из neurons_and_signal.txt?
        }
        variable_error     =   1073741824-list_of_neurons[200] ;
   //     std::cout << "list_of_neurons[201] = " << list_of_neurons[201]<< std::endl;
        if (variable_error<=0) // to the exit
            goto c;
        if (list_of_synapses[10100]==1) // to the exit
        {
            std::cout << "The values of all synapses are minimal and equal to 1." << std::endl;
            goto d;
        }
    e:
        if (list_of_synapses[variable_synapse_index_counter] >1)
                      list_of_synapses[variable_synapse_index_counter]  =  list_of_synapses[variable_synapse_index_counter]-1;
        
        if (list_of_synapses[variable_synapse_index_counter] ==1)
        {
            variable_synapse_index_counter = variable_synapse_index_counter+1;
            goto e;
        }
        if (variable_synapse_index_counter<10100)
            variable_synapse_index_counter=variable_synapse_index_counter+1;
        else
            variable_synapse_index_counter=0;
            goto b;
    c:
        std::cout << "The error has disappeared. Variable error = " << variable_error<< std::endl;
        std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
    d:
        fstream file;
        file.open("/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/synapses.txt",ios_base::out);
        
        vector<unsigned long long>::iterator itr;
        
        for(itr=list_of_synapses.begin();itr!=list_of_synapses.end();itr++)
        {
            file<<*itr<<endl;
        }
        
        file.close();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//        fstream file2;
//        file2.open("/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/neurons_and_signal.txt",ios_base::out);
        
//        vector<unsigned long long>::iterator itr2;
        
//        for(itr2=list_of_neurons.begin();itr2!=list_of_neurons.end();itr2++)
//        {
//            file2<<*itr2<<endl;
//        }
        
//        file2.close();
        
                fstream file2;
                file2.open("/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/201.txt",ios_base::out);
        
              //  vector<unsigned long long>::iterator itr2;
        
               // for(itr2=list_of_neurons.begin();itr2!=list_of_neurons.end();itr2++)
                {
                    //file2<<*itr2<<endl;
                    file2<< list_of_neurons[200];
                }
        
                file2.close();        
        
        
        std::cout << "The error has disappeared. Variable error = " << variable_error<< std::endl;
        std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
        std::cout << "Выход."<<std::endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

    return a.exec();
           exit(0);
}
