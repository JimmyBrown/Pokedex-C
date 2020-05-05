//
//  DVMPokemon.m
//  Pokedex-C
//
//  Created by Jimmy on 5/5/20.
//  Copyright © 2020 Karl Pfister. All rights reserved.
//

#import "DVMPokemon.h"

@implementation DVMPokemon

- (instancetype)initWithPokemonName:(NSString *)name identifier:(NSInteger)identifier abilities:(NSArray<NSString *> *)abilities spritePath:(NSString *)spritePath
{
    // Create the parent(siperclass) before we can create the child(subclass)
    self = [super init];
    
    if  (self != nil)
    {
        _name = name;
        _identifier = identifier;
        _abilities = abilities;
        _spritePath = spritePath;
    }
    return self;
}
@end

@implementation DVMPokemon (JSONConvertable)

-(DVMPokemon *)initWithDictionary:(NSDictionary<NSString *, id> *)topLevelDictionary
{
 // name, id, abilities, sprite
    // let name = topLevelDictionary["name"]
    NSString *name = topLevelDictionary[@"name"];
    // let id = topLevelDictionary["id] as? Int
    NSInteger identifier = [topLevelDictionary[@"id"] integerValue];
    NSArray *abilitiesArrayOfDict = topLevelDictionary[@"abilities"];
    // let abilities:[String] = []
    NSMutableArray<NSString *> *abilities = [NSMutableArray new];
    // Hint for Friday
    if (![name isKindOfClass:[NSNull class]] ||
        ![abilitiesArrayOfDict isKindOfClass:[NSArray class]])
    {return nil;}
    
    for (NSDictionary *dictionary in abilitiesArrayOfDict)
    {
        NSDictionary *abilityDict = dictionary[@"ability"];
        NSString *name = abilityDict[@"name"];
        [abilities addObject:name];
    }
    
    NSString *spritePath = topLevelDictionary[@"sprites"][@"front_shiny"];
    
    return [self initWithPokemonName:name identifier:identifier abilities:abilities spritePath:spritePath];
    
}

@end

// nil = nullable
