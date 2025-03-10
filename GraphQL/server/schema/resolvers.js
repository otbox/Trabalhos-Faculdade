const {UserList, MovieList} = require("../fkData")
const _ = require("lodash")

const resolvers = {
    Query : {
        users: () => {
            return UserList;
        },
        user: (parent, args) => {
            const id = args.id
            const user = _.find(UserList, { id : Number(id) });
            return user;
        },
        movies: () => {
            return MovieList;
        },
        movie (parent, args){
            const name = args.name 
            const movie = _.find(MovieList, { name })
            return movie;
        }
    },
    User: {
        favoriteMovies: () => {
            return _.filter(MovieList, (movie) => movie.yearOfPublication >= 2000 && movie.yearOfPublication <= 2010);
        }
    },
    Mutation : {
        createUser: (parent, args) => {
            const user = args.input
            let lastId = 0
            if (UserList.length > 0){
                lastId = UserList[UserList.length - 1].id
            }
            user.id = lastId + 1
            UserList.push(user)
        },
        updateUsername: (parent, args) => {
            const { id , newUsername} = args.input;
            let userUpdated = newUsername
            UserList.forEach((user) => {
                if (user.id === Number(id)){
                    user.username = newUsername
                    userUpdated = user
                }
            });
            return userUpdated
        },
        deleteUser: (parent, args) => {
            const {id} = args;
            _.remove(UserList, (user) => user.id === Number(id));
            return null;
        }
    }
}

module.exports = {resolvers}