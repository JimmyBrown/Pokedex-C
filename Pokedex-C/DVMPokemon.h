//
//  DVMPokemon.h
//  Pokedex-C
//
//  Created by Jimmy on 5/5/20.
//  Copyright © 2020 Karl Pfister. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DVMPokemon : NSObject

// let name: String
@property (nonatomic, readonly, copy) NSString *name;
@property (nonatomic, readonly) NSInteger identifier;

// let abilities: [String]
@property (nonatomic, copy, readonly) NSArray<NSString *> *abilities;

@property (nonatomic, copy, readonly) NSString *spritePath;

// return type

// init(name: String, identifier: Int, abilities: [String], spritePath: String) -> DVMPokemon

//1    2                 3              4     5  6
- (instancetype)initWithPokemonName:(NSString *)name
//                            7          8        9
                         identifier:(NSInteger)identifier
//                           10        11   12  13    14 15    16
                          abilities:(NSArray<NSString *>*)abilities
//                             17     18      19   20     21
                         spritePath:(NSString *)spritePath;

//1. The method type: Class (+) or Instance (-)
//2. Return type
//3. Method name with first external parameter name
//4. First parameter type
//5. Pointer to that first parameter
//6. Internal name for the first parameter
//7. Second external parameter name
//8. Second parameter type
//9. Second parameter name
//10. Third external parameter name
//11. Third parameter type
//12. Generic typecasting for third parameter <>
//13. Type for typecasting
//14. Pointer to the type for typecasting
//15. Pointer to the third parameter
//16. Internal name for third parameter
//17. Fourth external parameter name
//18. Fourth parameter type
//19. Pointer to fourth parameter
//20. Internal name for fourth parameter
//21. semicolon

@end

// extension DVMPokemon {
// }
@interface DVMPokemon (JSONConvertable)

// init(with topLevelDict: [String:any]) {
- (DVMPokemon *) initWithDictionary:(NSDictionary<NSString *, id> *)topLevelDictionary;
@end

NS_ASSUME_NONNULL_END
