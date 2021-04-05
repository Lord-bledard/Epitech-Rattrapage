import React from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import Gallery from '../Pages/Gallery';
import Favorites from '../Pages/Favorites';
import Search from '../Pages/Search';

const Tab = createBottomTabNavigator();

function GalerieScreen() {
  return (
    <View style={styles.mainContainer}>
      <Gallery />
    </View>
  );
}

function FavorisScreen() {
  return (
    <View style={styles.mainContainer}>
      <Favorites />
    </View>
  );
}

function RechercheScreen() {
  return (
    <View style={styles.mainContainer}>
      <Search />
    </View>
  );
}

export default function NavBar() {
    return (
        <Tab.Navigator>
            <Tab.Screen
                name='Galerie'
                component={GalerieScreen}
            />
            <Tab.Screen
                name='Recherche'
                component={RechercheScreen}
            />
            <Tab.Screen
                name='Favoris'
                component={FavorisScreen}
            />
        </Tab.Navigator>
    );
}

const styles = StyleSheet.create({
    mainContainer: {
        margin: 20,
        flex: 1,
    },
    title: {
      color: '#444',
      fontSize: 36,
      marginBottom: 10,
    },
});
