/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:39:02 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/14 17:14:46 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

    // ****************************************************************************** //
    //                 FORD-JOHNSON ALGORITHM: Merge-Insertion SORT                   //
    // ****************************************************************************** //  
                
    template <typename Container>
    void PMergeMe::sortContainer(Container& container)
    {
        if (container.size() < 2)
            return; 
         
    // ---------- nombre d'elements pair ou impair ---------- //
    
        bool hasOdd = (container.size() % 2 != 0);
    
        int oddElt = 0;
        size_t limit = container.size();
    
        if (hasOdd)
        {
            oddElt = container.back();
            --limit;
        }
        
    // --------- Former des Paires d'entiers: petits a gauche - grands a droite ----------- //

        std::vector<Pair> pairs;
    
        for (size_t i = 0; i < limit; i += 2)
        {
            Pair p;
        
            if (container[i] < container[i + 1])
            {
                p.small = container[i];
                p.large = container[i + 1];
            }
            else
            {
                p.small = container[i + 1];
                p.large = container[i];
            }
            pairs.push_back(p);
        }

    // ----------- Tri recursif des grands ------------ //
    
        Container larger;

        for (size_t i = 0; i < pairs.size(); ++i)
            larger.push_back(pairs[i].large);
        
        container = larger;
        sortContainer(container);
        larger = container;

    // ------------ Reconstitution des paires small -> large --------------- //

        std::vector<Pair> sortedPairs;
        std::vector<bool> used(pairs.size(), false);
    
        for (size_t i = 0; i < larger.size(); ++i)
        {
            for (size_t j = 0; j < pairs.size(); ++j)
            {
                if (!used[j] && pairs[j].large == larger[i])
                {
                    sortedPairs.push_back(pairs[j]);
                    used[j] = true;
                    break;
                }
            }
        }
        
    // ---------------- Main Chain ------------------ //
    
        Container mainChain;
    
        for (size_t i = 0; i < sortedPairs.size(); ++i)
            mainChain.push_back(sortedPairs[i].large); // contient les les grands elts tries recursivement

        // ------------------ Inserer les petits elts dans mainChain ------------------ //
        //          D'abord le 1er elt de smaller (car correspond au 1er elt de larger) 

        if (!sortedPairs.empty())
        {
            typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), sortedPairs[0].small);
            mainChain.insert(pos, sortedPairs[0].small);
        }
    
            // --- Ensuite, Utiliser la suite de Jacobsthal 
            // --- pour optimiser l'ordre d'insertion des petits par une recherche binaire
            // --- Ford-Johnson choisit les indices 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20, ...
            // --- et les frontieres sont Jacobsthal: 1, 3, 5, 11, 21, 43, ...
            // --- Entre 2 frontieres, on parcourt les indices a l'envers
    
        size_t previous = 1;
    
        for (int k = 3; ; ++k)
        {
            size_t current = jacobsthal(k);
        
            if (current > sortedPairs.size())
                current = sortedPairs.size();
        
        // on genere les indices a inserer a l'envers dans le groupe
            for (size_t i = current; i > previous; --i)
            {
                size_t index = i - 1;
            
                int value = sortedPairs[index].small;
                int bound = sortedPairs[index].large; 
            
            // Ensuite on ne cherche le small que jusqu'a son propre large
            // pour limiter la recherche binaire
            
                typename Container::iterator end = std::lower_bound(mainChain.begin(), mainChain.end(), bound);
                typename Container::iterator pos = std::lower_bound(mainChain.begin(), end, value);
                mainChain.insert(pos, value);
            }
            previous = current;
            if (current == sortedPairs.size())
                break;
        }

    // --- puis on insere l'element impair s'il existe
    
        if (hasOdd)
        {
            typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElt);
            mainChain.insert(pos, oddElt);
        }
    
        container = mainChain;
    }